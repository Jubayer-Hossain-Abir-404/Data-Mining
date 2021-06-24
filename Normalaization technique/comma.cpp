#include <bits/stdc++.h>
using namespace std;

int main()
{
    int bin,e,num,i,j,k,sum,boundary1,boundary2;
    string str;
    getline(cin, str);

    vector<int> vect;

    stringstream ss(str);

    while (ss >> i) {

        vect.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }

    for (size_t i = 0; i < vect.size(); i++)

        sort(vect.begin(),vect.end());

        /*cout << "\nSorted:";
        for(int x : vect)
            cout << x << " ";*/

            cout << "\nEnter bin size:";
            cin >> bin;

            num = vect.size();
            e = num / bin;

            int b[e][bin],avg[e], mean[e][bin];

            k = 0;

            cout<<"\nchoice 1: smoothing by means";
            cout<<"\nchoice 2: smoothing by boundary\n";
            int choice;
            cin>>choice;

            //bin generate

                for(i=0; i<e; i++)

                {

                cout << "BIN " << (i+1) << ": ";

                for(j=0; j<bin; j++)

                {

                b[i][j] = vect[j+k];

                cout << b[i][j] << " ";

                }

                k = k + bin;

                cout << endl;

                }

            if(choice==1){
                    cout<<"\nsmoothing by means:";



                //find average

                for(i=0; i<e; i++)

                {

                sum=0;

                for(j=0; j<bin; j++)

                {

                sum = sum + b[i][j];

                }

                avg[i] = sum / bin;

                }

                //give mean value to bin

                for(i=0; i<e; i++)

                {

                for(j=0; j<bin; j++)

                {

                mean[i][j] = avg[i];

                }

                }

                for(i=0; i<e; i++)

                {

                cout << "BIN " << (i+1) << ": ";

                for(j=0; j<bin; j++)

                {

                cout << mean[i][j] << " ";

                }

                cout << endl;

                }
            }
                else{
                //boundary:-------------------------
                cout<<"\nsmoothing by boundary:\n";

                    for(i=0; i<e; i++)

                    {

                    boundary1 = b[i][0];

                    boundary2 = b[i][bin-1];

                    for(j=0; j<bin; j++)

                    {

                    if(abs(b[i][j] - boundary1) < abs(b[i][j] - boundary2))

                    {

                    b[i][j] = boundary1;

                    }

                    else if(abs(b[i][j] - boundary1) > abs(b[i][j] - boundary2))

                    {

                    b[i][j] = boundary2;

                    }

                    else

                    {

                    b[i][j] = boundary1;

                    }

                    }

                    }

                    for(i=0; i<e; i++)

                    {

                    cout << "BIN " << (i+1) << ": ";

                    for(j=0; j<bin; j++)

                    {

                    cout << b[i][j] << " ";

                    }

                    cout << endl;

                    }
                }
}
