var
  a:array[1..50000] of longint;
  n,i,j,p,q,ans:longint;
begin
  readln(n);
  for i:=2 to n do read(a[i]);
  ans:=maxlongint;
  for i:=2 to n-1 do
    if ans>a[i+1]-a[i] then
      begin
        ans:=a[i+1]-a[i];
        p:=i;
      end;
  writeln(ans+a[n]);
  writeln(p+1,' 1 ',n,' ',p);
end.