var
  a,b:array[1..1000] of longint;
  f:array[-1..1000,-1..1000] of longint;
  n,i,j,k,ans:longint;
procedure sort1(m,n:longint);
var
  i,j,x,temp:longint;
begin
  x:=a[(m+n) shr 1];
  i:=m;
  j:=n;
  repeat
    while a[i]>x do i:=i+1;
    while a[j]<x do j:=j-1;
    if i<=j then
      begin
        temp:=a[i];
        a[i]:=a[j];
        a[j]:=temp;
        i:=i+1;
        j:=j-1;
      end;
    until i>j;
  if m<j then sort1(m,j);
  if i<n then sort1(i,n);
end;
procedure sort2(m,n:longint);
var
  i,j,x,temp:longint;
begin
  x:=b[(m+n) shr 1];
  i:=m;
  j:=n;
  repeat
    while b[i]>x do i:=i+1;
    while b[j]<x do j:=j-1;
    if i<=j then
      begin
        temp:=b[i];
        b[i]:=b[j];
        b[j]:=temp;
        i:=i+1;
        j:=j-1;
      end;
    until i>j;
  if m<j then sort2(m,j);
  if i<n then sort2(i,n);
end;
function gg(x,y:longint):longint;
begin
  if x*y=0 then exit(-1000000000);
  if b[x]>a[y] then exit(200);
  if b[x]=a[y] then exit(0);
  if b[x]<a[y] then exit(-200);
end;
function max(a,b:longint):longint;
begin
  max:=a;if a<b then max:=b;
end;
begin
  read(n);
  fillchar(f,sizeof(f),200);f[0,0]:=0;
  for i:=1 to n do read(b[i]);{Ìï¼É}
  for i:=1 to n do read(a[i]);
  sort1(1,n);sort2(1,n);
  for i:=0 to n do
    for j:=0 to n-i do
      if i+j>0 then
      f[i,j]:=max(f[i-1,j]+gg(i,i+j),f[i,j-1]+gg(n-j+1,i+j));
  ans:=-maxlongint;
  for i:=0 to n do
    ans:=max(ans,f[i,n-i]);
  writeln(ans);
end.
