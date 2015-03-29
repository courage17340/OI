var
  a,b:array[0..10000] of longint;
  i,j,n:longint;
procedure quicksorta(m,n:longint);
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
  if m<j then quicksorta(m,j);
  if i<n then quicksorta(i,n);
end;
procedure quicksortb(m,n:longint);
var
  i,j,x,temp:longint;
begin
  x:=b[(m+n) div 2];
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
  if m<j then quicksortb(m,j);
  if i<n then quicksortb(i,n);
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);readln;quicksorta(1,n);
  for i:=1 to n do read(b[i]);quicksortb(1,n);
  j:=0;
  for i:=1 to n do j:=j+abs(a[i]-b[i]);
  writeln(j);
end.