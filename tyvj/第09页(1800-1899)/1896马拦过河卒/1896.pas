var
  a,f:array[-1..20,-1..20] of comp;
  n,m,x,y:longint;
procedure init;
begin
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),0);
  readln(n,m,x,y);
  a[x,y]:=-1;
  a[x-2,y-1]:=-1;
  a[x-2,y+1]:=-1;
  a[x-1,y-2]:=-1;
  a[x-1,y+2]:=-1;
  a[x+1,y-2]:=-1;
  a[x+1,y+2]:=-1;
  a[x+2,y-1]:=-1;
  a[x+2,y+1]:=-1;
  f[0,0]:=1;
end;
procedure work;
var
  i,j:longint;
begin
  for i:=0 to n do
    for j:=0 to m do
      if a[i,j]>-1 then
        begin
          if a[i-1,j]>-1 then f[i,j]:=f[i,j]+f[i-1,j];
          if a[i,j-1]>-1 then f[i,j]:=f[i,j]+f[i,j-1];
        end;
  writeln(f[n,m]:0:0);
end;
begin
  init;
  work;
end.