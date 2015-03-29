var
  w,v:array[1..4000] of longint;
  f:array[0..13000] of longint;
  n,m,i,j:longint;
begin
  fillchar(f,sizeof(f),0);
  readln(n,m);
  for i:=1 to n do readln(w[i],v[i]);
  for i:=1 to n do
    for j:=m downto w[i] do
      if f[j]<f[j-w[i]]+v[i] then f[j]:=f[j-w[i]]+v[i];
  writeln(f[m]);
end.