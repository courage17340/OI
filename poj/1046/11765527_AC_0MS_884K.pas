type rec=record r,g,b:longint;end;
var
  a:array[1..16] of rec;
  n,i,r,g,b:longint;
function find:longint;
var
  i,j,k:longint;
begin
  j:=0;k:=maxlongint;
  for i:=1 to 16 do
    if (r-a[i].r)*(r-a[i].r)+(g-a[i].g)*(g-a[i].g)+(b-a[i].b)*(b-a[i].b)<k then
      begin
        j:=i;
        k:=(r-a[i].r)*(r-a[i].r)+(g-a[i].g)*(g-a[i].g)+(b-a[i].b)*(b-a[i].b);
      end;
  exit(j);
end;

begin
  for i:=1 to 16 do readln(a[i].r,a[i].g,a[i].b);
  while true do
    begin
      readln(r,g,b);
      if r=-1 then break;
      writeln('(',r,',',g,',',b,') maps to (',a[find].r,',',a[find].g,',',a[find].b,')');
    end;
end.