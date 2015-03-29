var
  f:array[1..1000] of longint;
  n,i,j:longint;
begin
  readln(n);
  for i:=1 to n do f[i]:=1;
  for i:=2 to n do
    for j:=1 to i div 2 do
      f[i]:=f[i]+f[j];
  writeln(f[n]);
  readln;
end.