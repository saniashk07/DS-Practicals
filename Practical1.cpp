#include <iostream> using namespace std; int main(){
int cities=3; int months=4;
int Rainfall [cities][months];



cout<<"Enter temperature data for 3 cities for 4 months:\n"; for (int i =0;i<3;i++){
cout<<"City"<<i+1<<"\n"; for(int j=0;j<4;j++){
 
cout<<"months"<<j+1<<":"; cin>>Rainfall[i][j];
}

}

cout<<"\n Rainfall data table"; cout<<"City\nmonths\t";
for (int j=0;j<4;j++){

cout<<"Month"<<j+1<<"\t";

}

cout<<"Average\n"; for(int i=0;i<3;i++){
int sum=0; cout<<"cities"<<i+1<<"\t"; for(int j=0;j<4;j++){
cout<<Rainfall[i][j]<<"\t"; sum+=Rainfall[i][j];
}

int average=sum/months; cout<<average<<endl;
}

return 0;

}

