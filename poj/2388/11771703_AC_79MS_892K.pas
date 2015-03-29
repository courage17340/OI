var
  a:array[1..10000] of longint;
  n,i:longint;
procedure sort(m,n:longint);
var
  i,j,x,t:longint;
begin
  i:=m;
  j:=n;
  x:=a[(m+n) shr 1];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then
      begin
        t:=a[i];
        a[i]:=a[j];
        a[j]:=t;
        inc(i);
        dec(j);
      end;
   until i>j;
  if m<j then sort(m,j);
  if i<n then sort(i,n);
end;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  sort(1,n);
  writeln(a[n shr 1+1]);
end.