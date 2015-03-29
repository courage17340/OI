var
  a:array[0..10000] of longint;
  s:array[0..10000] of ansistring;
  n,i:longint;
procedure quick1(m,n:longint);
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
  if m<j then quick1(m,j);
  if i<n then quick1(i,n);
end;
procedure quick2(m,n:longint);
var
  i,j:longint;
  x,temp:ansistring;
begin
  x:=s[(m+n) div 2];
  i:=m;
  j:=n;
  repeat
    while s[i]<x do i:=i+1;
    while s[j]>x do j:=j-1;
    if i<=j then
      begin
        temp:=s[i];
        s[i]:=s[j];
        s[j]:=temp;
        i:=i+1;
        j:=j-1;
      end;
    until i>j;
  if m<j then quick2(m,j);
  if i<n then quick2(i,n);
end;
begin
  readln(n);
  for i:=1 to n do readln(s[i]);
  for i:=1 to n do readln(a[i]);
  quick1(1,n);
  quick2(1,n);
  for i:=1 to n do writeln(s[i],' ',a[i]);
end.