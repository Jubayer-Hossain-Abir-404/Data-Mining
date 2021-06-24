#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
float real_numbers[1024],maximum,minimum,v[100];
int length=0;

void getting_max_min()
{
    maximum=real_numbers[0];
    minimum =real_numbers[0];
    for(int i=0; i<length; i++)
    {
        if(real_numbers[i]>maximum)
        {
            maximum= real_numbers[i];
        }
        else if(real_numbers[i]<minimum)
        {
            minimum =real_numbers[i];
        }
    }
}
void z_score_normalization()
{
    float sum=0,mean,standard_deviation,temp1=0;
    for(int i=0; i<length; i++)
    {
        sum+=real_numbers[i];
    }
    mean=sum/length;
    for(int i=0; i<length; i++)
    {
        temp1=temp1+pow(real_numbers[i]-mean,2);
    }

    standard_deviation=sqrt(temp1/length);
    for(int i=0;i<length;i++)
    {
        v[i]=(real_numbers[i]-mean)/standard_deviation;
    }
}

void min_max_normalization(int new_min, int new_max)
{
    getting_max_min();
    for(int i=0; i<length; i++)
    {
        v[i]= (((real_numbers[i]-minimum)*(new_max-new_min))/(maximum-minimum))+ new_min;
    }
}

void decimal_scaling_normalization()
{
    float temp;
    int c=0;
    getting_max_min();
    while(maximum>=1)
    {
      maximum=maximum/10;
      c++;
    }
    for(int i=0;i<length;i++)
    {
        v[i]=real_numbers[i]/pow(10,c);
    }
}

void show_output()
{
    float temp;
    printf("Sample Output\n");
    for(int i=0; i<length; i++)
    {
        int c=0,a;
        float y=fmod(v[i],1);
        if(y!=0)
        {
            temp=v[i];
            while(y!=0)
            {
                temp=temp/0.1;
                y=fmod(temp,1);
                c++;
                if(c==4)
                {
                    break;
                }
            }
        }
        if(i!=length-1)
        {
            if(c==4)
            {
                printf("%.3f, ",v[i]);
            }
            else
            {
                printf("%g, ",v[i]);
            }
        }

        else
        {
            if(c==4)
            {
                printf("%.3f ",v[i]);
            }
            else
            {
                printf("%g ",v[i]);
            }
        }
    }
}


int main()
{
    int choice;
    char buffer[1024];
    char *aux;
    printf("Sample Input\n");
    fgets(buffer,1023,stdin);
    aux=strtok(buffer, ",");
    while(aux)
    {
        real_numbers[length]=atof(aux);
        length++;
        aux=strtok(NULL, ",");
    }
    while(1)
    {
        printf("Choice = ");
        scanf("%d",&choice);
        if(choice==1)
        {
            int new_min, new_max;
            printf("New min = ");
            scanf("%d",&new_min);
            printf("New max = ");
            scanf("%d", &new_max);
            min_max_normalization(new_min,new_max);
        }
        else if(choice==2)
        {
            z_score_normalization();
        }
        else if(choice==3)
        {
            decimal_scaling_normalization();
        }
        else
        {
            break;
        }
        show_output();
        printf("\n");
    }
}


