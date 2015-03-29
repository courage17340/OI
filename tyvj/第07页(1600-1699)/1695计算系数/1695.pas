var
  a,b,k,n,m,i,j:longint;
  f:array[-1..1010,-1..1010] of longint;
begin
  fillchar(f,sizeof(f),0);
  f[0,0]:=1;
  readln(a,b,k,n,m);
  a:=a mod 10007;b:=b mod 10007;
  for i:=1 to k do
    for j:=0 to i do
       f[j,i-j]:=(a*f[j-1,i-j]+b*f[j,i-j-1])mod 10007;
  writeln(f[n,m]);
end.