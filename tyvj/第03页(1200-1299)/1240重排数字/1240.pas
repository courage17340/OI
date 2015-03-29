var
  n,k,i,j,x:longint;
  a:array[0..102] of longint;
begin
  read(n,k);
  for i:=1 to n do read(a[i]);
  x:=n div k;
  if n mod k>0 then inc(x);
  for i:=1 to x do
    begin
      for j:=0 to k-1 do
        if x*j+i<=n then write(a[x*j+i]:4);
      writeln;
    end;
end.