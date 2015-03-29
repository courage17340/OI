var
  a:array[0..10000] of longint;
  n,i,k,x:longint;
procedure quick(m,n:longint);
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
  if m<j then quick(m,j);
  if i<n then quick(i,n);
end;
procedure print(t:boolean);
begin
  if t then writeln('YES') else writeln('NO');
  writeln(x);halt;
end;
begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  quick(1,n);
  x:=a[n-k+1]-a[k];
  if x<2 then print(false);
  for i:=2 to trunc(sqrt(x)) do if x mod i=0 then print(false);
  print(true);
end.