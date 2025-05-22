//或操作
void Or(ll *x,int n,int op){
  for(int l=1;l<n;l<<=1){
    for(int st=0;st<n;st+=l*2){
      for(int i=0;i<l;i++){
		ll u=x[st+i],v=x[st+l+i];
		if(op==1) x[st+i]=u,x[st+l+i]=(v+u)%mod;
		else x[st+i]=u,x[st+l+i]=(v+mod-u)%mod;
      }
    }
  }
}

//与运算
void And(ll *x,int n,int op){
  for(int l=1;l<n;l<<=1){
    for(int st=0;st<n;st+=l*2){
      for(int i=0;i<l;i++){
		ll u=x[st+i],v=x[st+l+i];
		if(op==1) x[st+i]=(u+v)%mod,x[st+l+i]=v;
		else x[st+i]=(u+mod-v)%mod,x[st+l+i]=v;
      }
    }
  }
}

//异或
void Xor(ll *x,int n,int op){
  for(int l=1;l<n;l<<=1){
    for(int st=0;st<n;st+=l*2){
      for(int i=0;i<l;i++){
		ll u=x[st+i],v=x[st+l+i];
		if(op==1) x[st+i]=(u+v)%mod,x[st+l+i]=(u+mod-v)%mod;
		else x[st+i]=(u+v)%mod*499122177%mod,x[st+l+i]=(u+mod-v)%mod*499122177%mod;
      }
    }
  }
}
