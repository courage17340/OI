var
  f:array[0..1000] of longint;
  n,i,j,k:longint;
begin
  fillchar(f,sizeof(f),0);
  readln(n,k);
  f[0]:=1;
  for i:=1 to k do
    for j:=i to n do
      f[j]:=f[j]+f[j-i];
  writeln(f[n]);
end.