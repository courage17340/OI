type
  rec=record x,y,k:longint;end;
var
  a:array[1..10000] of rec;
  i,j,m,n,x,y,x1,y1,ans,k:longint;
function ok(p:rec):boolean;
begin
  if (p.x>x1)or(p.x<x) then exit(false);
  if (p.y>y1)or(p.y<y) then exit(false);
  exit(true);
end;
begin
  read(n);
  i:=0;
  while true do
    begin
      read(m);
      if m=3 then break;
      if m=1 then begin read(x,y,k);inc(i);a[i].x:=x;a[i].y:=y;a[i].k:=k;end;
      if m=2 then
        begin
          read(x,y,x1,y1);
          ans:=0;
          for j:=1 to i do
            if ok(a[j]) then inc(ans,a[j].k);
          writeln(ans);
        end;
    end;
end.