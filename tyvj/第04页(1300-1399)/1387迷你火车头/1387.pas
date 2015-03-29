var
  a,sum:array[0..50000] of longint;
  f:array[0..3,0..50000] of longint;
  n,i,j,m:longint;
function max(a,b:longint):longint;
begin
  max:=a;if a<b then max:=b;
end;
begin
  read(n);sum[0]:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      sum[i]:=sum[i-1]+a[i];
    end;
  fillchar(f,sizeof(f),0);
  read(m);
  for i:=1 to 3 do
    for j:=m*i to n-m*(3-i) do
      f[i,j]:=max(f[i,j-1],f[i-1,j-m]+sum[j]-sum[j-m]);
  writeln(f[3,n]);
  readln;readln;
end.
