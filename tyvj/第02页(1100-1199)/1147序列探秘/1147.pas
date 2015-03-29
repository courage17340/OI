var
  f:array[-200000..200000] of longint;
  n,k,i,j,x:longint;
begin
  readln(n,k);
  fillchar(f,sizeof(f),0);
  j:=0;
  for i:=1 to n do
    begin
      read(x);
      f[x]:=f[x-k]+1;
      if j<f[x] then j:=f[x];
    end;
  writeln(j);
end.