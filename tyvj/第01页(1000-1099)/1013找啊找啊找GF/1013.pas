var
 rmb,rp,time:array[0..110] of longint;
 f,ct:array[0..110,0..110] of longint;
 n,m,r,ans,max,i,j,k:longint;
begin
 readln(n);
 for i:=1 to n do readln(rmb[i],rp[i],time[i]);
 readln(m,r);
 fillchar(f,sizeof(f),0);
 fillchar(ct,sizeof(ct),0);
 f[0,0]:=1;
 for i:=1 to n do
  for j:=m downto rmb[i] do
   for k:=r downto rp[i] do
    if f[j-rmb[i],k-rp[i]]>0
     then
      begin
       if f[j-rmb[i],k-rp[i]]+1>f[j,k]
        then
         begin
          f[j,k]:=f[j-rmb[i],k-rp[i]]+1;
          ct[j,k]:=ct[j-rmb[i],k-rp[i]]+time[i];
         end
        else if (f[j-rmb[i],k-rp[i]]+1=f[j,k])and(ct[j-rmb[i],k-rp[i]]+time[i]<ct[j,k])
         then ct[j,k]:=ct[j-rmb[i],k-rp[i]]+time[i];
      end;
 max:=0;
 ans:=maxlongint;
 for j:=1 to m do
  for k:=1 to r do
   if f[j,k]>max
    then
     begin
      max:=f[j,k];
      ans:=ct[j,k];
     end
    else
     if (f[j,k]=max)and(ans>ct[j,k]) then ans:=ct[j,k];
 writeln(ans);
end.