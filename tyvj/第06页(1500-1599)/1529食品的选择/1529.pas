var
  a:array[0..10000,1..2] of longint;
  f:array[0..10000] of longint;
  n,i,j:longint;
function max(a,b:longint):longint;
begin
  max:=a;if b>a then max:=b;
end;
procedure sort(m,n:longint);
var
  i,j,x,y,temp:longint;
begin
  x:=a[(m+n) shr 1,1];
  y:=a[(m+n) shr 1,2];
  i:=m;
  j:=n;
  repeat
    while (a[i,1]<x)or(a[i,1]=x)and(a[i,2]<y) do i:=i+1;
    while (a[j,1]>x)or(a[j,1]=x)and(a[j,2]>y) do j:=j-1;
    if i<=j then
      begin
        temp:=a[i,1];
        a[i,1]:=a[j,1];
        a[j,1]:=temp;
        temp:=a[i,2];
        a[i,2]:=a[j,2];
        a[j,2]:=temp;
        i:=i+1;
        j:=j-1;
      end;
    until i>j;
  if m<j then sort(m,j);
  if i<n then sort(i,n);
end;
begin
  read(n);
  for i:=1 to n do read(a[i,1],a[i,2]);
  sort(1,n);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do f[i]:=1;
  for i:=2 to n do
    for j:=1 to i-1 do
      if (a[i,1]>=a[j,1])and(a[i,2]>=a[j,2]) then
        f[i]:=max(f[i],f[j]+1);
  j:=0;
  for i:=1 to n do if j<f[i] then j:=f[i];
  writeln(j);
  readln;readln;
end.