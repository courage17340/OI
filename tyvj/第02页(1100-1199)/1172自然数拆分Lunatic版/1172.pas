var
  f:array[0..5000] of int64;
  n,i,j:longint;
begin
  readln(n);
  fillchar(f,sizeof(f),0);
  f[0]:=1;
  for i:=1 to n-1 do
    for j:=i to n do
      f[j]:=(f[j]+f[j-i]) mod 2147483648;
  writeln(f[n]);
end.