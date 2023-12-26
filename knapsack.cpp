#include<iostream>
using namespace std;

void knap(int n,float weight[],float cost[],float c){
	int i,j;
	float x[20],tp=0;
	
	for(i=0;i<n;i++){
		x[i]=0.0;
	}
	
	for(i=0;i<n;i++){
		if(weight[i]>c){
			break;
		}
		else{
			x[i]=1.0;
			tp=tp+cost[i];
			c=c-weight[i];
		}
	}
	
	if(i<n){
	x[i]=c/weight[i];
	tp=tp+(x[i]*cost[i]);
	
	}
	//printing ratio
	for(i=0;i<n;i++){
		cout<<" "<<x[i]<<"";
	}
	cout<<endl;
	cout<<"Max profit is = "<<tp;
	
	
	
}




int main(){
	int num,i,j;
	float weight[20],cost[20],cap;
	cout<<"Number of observer is = ";
	cin>>num;
	
	for(i=0;i<num;i++){
		cin>>weight[i];
		cin>>cost[i];
	}
	
	for(i=0;i<num;i++){
		cout<<" "<<weight[i]<<" "<<cost[i]<<endl;
	}
	
	cout<<"Capacity is = ";
	cin>>cap;
	
	float ratio[30];
	
	for(i=0;i<num;i++){
		ratio[i]=cost[i]/weight[i];
	}
	
	for(i=0;i<num;i++){
		for(j=i+1;j<num;j++){
			if(ratio[i]<ratio[j]){
				swap(ratio[i],ratio[j]);
				swap(weight[i],weight[j]);
				swap(cost[i],cost[j]);
			}
		}
	}
	
	knap(num,weight,cost,cap);
	
	
	
}