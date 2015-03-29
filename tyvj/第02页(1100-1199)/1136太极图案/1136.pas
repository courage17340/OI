uses math;
var
  n,m,i,j,ans:longint;
  a,a1,a0,b1,b0,f:array[-1..1000,-1..1000]of integer;
begin
  readln(n,m);
  fillword(a,sizeof(a)div 2,2);
  fillword(a1,sizeof(a1)div 2,1);
  fillword(a0,sizeof(a0)div 2,1);
  fillword(b1,sizeof(b1)div 2,1);
  fillword(b0,sizeof(b0)div 2,1);
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(a[i,j]);
        if (a[i,j]=1)and(a[i,j-1]=1) then a1[i,j]:=a1[i,j-1]+1;
        if (a[i,j]=0)and(a[i,j-1]=0) then a0[i,j]:=a0[i,j-1]+1;
        if (a[i,j]=1)and(a[i-1,j]=1) then b1[i,j]:=b1[i-1,j]+1;
        if (a[i,j]=0)and(a[i-1,j]=0) then b0[i,j]:=b0[i-1,j]+1;
      end;
  ans:=0;
  for i:=1 to n do
    for j:=1 to m do
      begin
        f[i,j]:=min(a0[i,j],b0[i,j]);
        f[i,j]:=min(f[i,j],f[i-1,j-1]+2);
        f[i,j]:=min(f[i,j],a1[i-f[i-1,j-1]-1,j-1]);
        f[i,j]:=min(f[i,j],b1[i,j-f[i-1,j-1]-2]);
        if ans<f[i,j] then ans:=f[i,j];
      end;
  writeln(ans);
end.
