var
  f:array[0..30,0..30] of longint;
  m,n:longint;
procedure init;
begin
  readln(n,m);
  fillchar(f,sizeof(f),0);
end;
procedure work;
var
  i,j,p,q:longint;
begin
  f[1,0]:=1;
  for j:=1 to m do
    for i:=1 to n do
      begin
        p:=i-1;
        q:=i+1;
        if p=0 then p:=n;
        if q=n+1 then q:=1;
        f[i,j]:=f[p,j-1]+f[q,j-1];
      end;
  write(f[1,m]);
end;
begin
  init;
  work;
end.