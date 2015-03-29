var
  a:array[0..100] of longint;
  f:array[0..10000] of longint;
  i,j,m,n:longint;
begin
  readln(n,m);
  for i:=1 to n do read(a[i]);readln;
  f[0]:=1;
  for i:=1 to n do
    for j:=m downto a[i] do
      f[j]:=f[j]+f[j-a[i]];
  writeln(f[m]);
end.