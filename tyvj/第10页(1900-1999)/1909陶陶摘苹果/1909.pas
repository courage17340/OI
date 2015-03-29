var
  a:array[1..10] of longint;
  i,j,ans:longint;
begin
  for i:=1 to 10 do read(a[i]);
  readln(j);
  j:=j+30;
  ans:=0;
  for i:=1 to 10 do
    if a[i]<=j then inc(ans);
  writeln(ans);
end.