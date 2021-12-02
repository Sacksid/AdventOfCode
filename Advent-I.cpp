struct Trio
{
    int var1;
    int var2;
    int var3; 
};
int getSum(Trio t){
    return (t.var1+t.var2+t.var3);
    }
Trio  advanceVar(Trio t,int next){
    t.var1=t.var2;
    t.var2=t.var3;
    t.var3=next;
    return t;
}
int main(void)
{
    Trio t;
    cin>>t.var1;
    cin>>t.var2;
    cin>>t.var3;
    int lastSum=getSum(t);
    int pivot;
    int count=0;
    while(cin>>pivot)
    {
        t=advanceVar(t,pivot);
        if(getSum(t)>lastSum)
        {
            count++;
        }
        lastSum=getSum(t);
    }
    cout<<count<<endl;
}
