var
  f:array[0..1000001] of longint;
  i,k,n:longint;
begin
  f[1]:=1;
  f[2]:=2;
  k:=1000000000;
  readln(n);
  for i:=3 to n do
  if i mod 2=0
    then f[i]:=(f[i-1]+f[i div 2] )mod k
    else f[i]:=f[i-1];
  writeln(f[n]);
end.