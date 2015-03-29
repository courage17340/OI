var
  f:array[0..40000] of boolean;
  i,j,m,n,k,ans:longint;
  a,h,c:array[1..400] of longint;
procedure qsort(m,n:longint);
var
  i,j,x,temp:longint;
begin
  x:=a[(m+n) div 2];
  i:=m;
  j:=n;
  repeat
    while a[i]<x do i:=i+1;
    while a[j]>x do j:=j-1;
    if i<=j then
      begin
        temp:=a[i];a[i]:=a[j];a[j]:=temp;
        temp:=h[i];h[i]:=h[j];h[j]:=temp;
        temp:=c[i];c[i]:=c[j];c[j]:=temp;
        i:=i+1;
        j:=j-1;
      end;
    until i>j;
  if m<j then qsort(m,j);
  if i<n then qsort(i,n);
end;
begin
  read(n);
  for i:=1 to n do read(h[i],a[i],c[i]);
  qsort(1,n);
  f[0]:=true;
  for i:=1 to n do
    for j:=1 to c[i] do
      for k:=a[i] downto h[i] do
        if f[k-h[i]] then f[k]:=true;
  k:=a[n];
  while not f[k] do dec(k);
  writeln(k);
end.
