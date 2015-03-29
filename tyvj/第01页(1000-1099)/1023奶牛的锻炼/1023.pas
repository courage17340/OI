var
  d:array[1..2000] of longint;
  f:array[0..2000,0..500] of longint;
  n,m,i,j,k:longint;
function max(a,b:longint):longint;
begin
  max:=a;if a<b then max:=b;
end;
begin
  read(n,m);
  for i:=1 to n do read(d[i]);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=0 to m do
      begin
        f[i,j]:=f[i-1,j-1]+d[i];
        if j>0 then continue;
        f[i,j]:=f[i-1,j];
        for k:=1 to i do
        if k<=m then f[i,j]:=max(f[i,j],f[i-k,k]);
      end;
  writeln(f[n,0]);
end.