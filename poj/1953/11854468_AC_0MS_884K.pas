var
  f:array[1..45] of int64;
  n,i,x:longint;
begin
  f[1]:=2;
  f[2]:=3;
  for i:=3 to 45 do
    f[i]:=f[i-1]+f[i-2];
  readln(n);
  for i:=1 to n do
    begin
      readln(x);
      writeln('Scenario #',i,':');
      writeln(f[x]);
      writeln;
    end;
end.