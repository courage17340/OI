var
  a:array[0..10000] of longint;
  ans:int64;
  n,i,j:longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  ans:=0;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      ans:=ans+abs(a[i]-a[j]);
  ans:=ans*2;
  writeln(ans);
end.