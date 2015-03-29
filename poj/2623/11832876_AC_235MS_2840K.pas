var
  a:array[1..250000] of int64;
  n,i,j:longint;
  s:int64;
procedure find(k,m,n:longint);
var
  i,j:longint;
  x,t:int64;
begin
  if m=n then exit;
  x:=a[(m+n) shr 1];
  i:=m;
  j:=n;
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
  if (k<=j)and(m<j) then find(k,m,j);
  if (i<=k)and(i<n) then find(k,i,n);
end;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  find((n+1) shr 1,1,n);
  if odd(n)
    then
      writeln(a[(n+1) shr 1],'.0')
    else
      begin
        find(n shr 1+1,1,n);
        s:=a[n shr 1]+a[n shr 1+1];
        write(s div 2,'.');
        if s mod 2=1 then writeln(5) else writeln(0);
      end;
end.