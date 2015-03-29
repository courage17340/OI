var
  n,i:longint;
  a:array[0..10000] of ansistring;
procedure quicksort(m,n:longint);
var
  i,j:longint;
  x,temp:ansistring;
begin
  x:=a[(m+n) div 2];
  i:=m;
  j:=n;
  repeat
    while a[i]<x do i:=i+1;
    while a[j]>x do j:=j-1;
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
  readln(n);
  for i:=1 to n do readln(a[i]);
  quicksort(1,n);
  for i:=1 to n do writeln(a[i]);
end.