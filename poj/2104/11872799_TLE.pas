var
  a,b:array[1..100000] of longint;
  n,m,i,j,x,y,k:longint;
procedure find(m,n,k:longint);
var
  i,j,x,t:longint;
begin
  if m=n then
    begin
      writeln(a[m]);
      exit;
    end;
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
  if (m<=j)and(k<=j) then find(m,j,k);
  if (i<=n)and(k>=i) then find(i,n,k);
  if (j<k)and(k<i) then find(j+1,i-1,k);
end;
begin
  readln(n,m);
  for i:=1 to n do read(b[i]);
  a:=b;
  for i:=1 to m do
    begin
      readln(x,y,k);
      find(x,y,k+x-1);
      for j:=x to y do a[j]:=b[j];
    end;
end.