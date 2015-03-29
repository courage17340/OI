type
  rec=record x,y,v:longint;end;
var
  a:array[0..10000] of rec;
  f:array[0..10000] of longint;
  v1,v2:array[0..10000] of boolean;
  n,m,i,min:longint;
  ok:boolean;
procedure print;
begin
  writeln(-1);
  halt;
end;
begin
  read(n,m);
  for i:=1 to m do read(a[i].x,a[i].y,a[i].v);
  fillchar(f,sizeof(f),0);
  fillchar(v1,sizeof(v1),false);
  fillchar(v2,sizeof(v2),false);
  f[a[1].x]:=0;f[a[1].y]:=a[1].v;
  v2[a[1].x]:=true;v2[a[1].y]:=true;
  repeat
    ok:=true;
    for i:=2 to m do
      if not v1[i] then if v2[a[i].x] or v2[a[i].y] then
        begin
          v1[i]:=true;ok:=false;
          if v2[a[i].x] and v2[a[i].y] then if f[a[i].x]+a[i].v<>f[a[i].y] then print;
          if v2[a[i].x] then f[a[i].y]:=f[a[i].x]+a[i].v;
          if v2[a[i].y] then f[a[i].x]:=f[a[i].y]-a[i].v;
          v2[a[i].x]:=true;v2[a[i].y]:=true;
        end;
    if ok then break;
    until false;
  min:=maxlongint;
  for i:=1 to n do if min>f[i] then min:=f[i];
  for i:=1 to n do writeln(f[i]-min);
end.