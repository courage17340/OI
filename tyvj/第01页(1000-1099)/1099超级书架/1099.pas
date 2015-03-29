var
  a:array[0..20000] of longint;
  n,b,i,j:longint;
procedure quicksort(m,n:longint);
var
  i,j,x,temp:longint;
begin
  x:=a[(m+n) div 2];
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
  if m<j then quicksort(m,j);
  if i<n then quicksort(i,n);
end;
begin
  read(n,b);
  for i:=1 to n do read(a[i]);
  quicksort(1,n);
  j:=0;
  i:=0;
  while j<b do
    begin
      inc(i);
      j:=j+a[i];
    end;
  writeln(i);
end.