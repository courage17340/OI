var
  a:array[1..100] of longint;
  f:array[1..100,1..100] of longint;
  n,i,j,k:longint;
function max(a,b:longint):longint;
begin
  max:=a;if a<b then max:=b;
end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do f[i,i]:=a[i];
  for j:=1 to n-1 do
    for i:=1 to n-j do
      begin
        f[i,i+j]:=abs(a[i]-a[i+j])*(j+1);
        for k:=i to i+j-1 do
          f[i,i+j]:=max(f[i,i+j],f[i,k]+f[k+1,i+j]);
      end;
  writeln(f[1,n]);
end.
