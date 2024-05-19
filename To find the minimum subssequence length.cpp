// To find the minimum subsequence length


int n;
cin << n;
  int a[n],p[n+1];p[0]=0;
int a[n],p[n+1];
p[0] = 0;
        int s=0;
        for(int i=0;i<n;i++){
            cin>>a[i];s+=a[i];
            p[i+1]=p[i]+a[i];
        }
        int mx=INT_MAX,pmx=0;
        for(int i=2;i<n+1;i++){
            mx=min(mx,p[i]-pmx);
            pmx=max(pmx,p[i-1]);
        }
        cout<< s - mx + abs(mx) << endl;
