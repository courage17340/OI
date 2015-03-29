var
  a:array[1..2000] of longint;
  f:array[-1..2000,-1..2000] of longint;
  i,j,m,n:longint;
function max(a,b:longint):longint;
begin
  max:=a;if a<b then max:=b;
end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  fillchar(f,sizeof(f),0);
  for i:=0 to n do
    for j:=0 to n-i do
      f[i,j]:=max(f[i-1,j]+a[i]*(i+j),f[i,j-1]+a[n-j+1]*(i+j));
  m:=0;
  for i:=0 to n do if m<f[i,n-i] then m:=f[i,n-i];
  writeln(m);
end.
