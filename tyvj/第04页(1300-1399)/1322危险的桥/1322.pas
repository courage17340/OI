type rec=record x,y:longint;end;
var
  a,b:array[0..500] of rec;
  f:array[0..200] of longint;
  n,m,i,j,k,p:longint;
function top(x:longint):longint;
begin
  top:=x;
  while f[x]<>x do x:=f[x];
  f[top]:=x;
  exit(x);
end;
procedure sort;
var
  i,j:longint;
  t:rec;
begin
  for i:=1 to p-1 do
    for j:=i+1 to p do
      if (b[i].x>b[j].x)or(b[i].x=b[j].x)and(b[i].y>b[j].y) then
        begin t:=b[i];b[i]:=b[j];b[j]:=t;end;
end;
begin
  p:=0;
  read(n,m);
  for i:=1 to m do
    begin
     read(a[i].x,a[i].y);
     if a[i].x>a[i].y then begin j:=a[i].x;a[i].x:=a[i].y;a[i].y:=j;end;
    end;
  for i:=1 to m do
    begin
      for j:=1 to 200 do f[j]:=j;
      for j:=1 to m do if j<>i then if top(a[j].x)<>top(a[j].y) then f[top(a[j].x)]:=top(a[j].y);
      k:=top(1);
      for j:=2 to n do if top(j)<>k then begin inc(p);b[p].x:=a[i].x;b[p].y:=a[i].y;break;end;
    end;
  sort;
  for i:=1 to p do writeln(b[i].x,' ',b[i].y);
end.