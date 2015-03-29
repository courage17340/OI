var
  a:array[0..30000] of longint;
  n,p,i:longint;
  s:int64;
procedure quicksort(m,n:longint);
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
  readln(n,p);
  for i:=1 to n do read(a[i]);readln;
  quicksort(1,n);
  a[0]:=-1;
  s:=0;
  for i:=1 to n do
    begin
      s:=int64(s + int64(i)*int64(a[i])) mod 1000;
      if a[i]=a[i-1] then s:=int64(s+int64(p)) mod 1000;
    end;
  writeln(s);
end.