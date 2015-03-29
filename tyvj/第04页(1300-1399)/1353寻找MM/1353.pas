type
  arr=record
        x,y:longint;
      end;
var
  a:array[0..20,0..20] of char;
  f:array[0..1000] of arr;
  n,i,j,m,ans,x1,y1:longint;
function ff(x:longint):longint;
begin
  ff:=x+1;
  if ff=1001 then ff:=0;
end;
begin
  ans:=0;
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do begin read(a[i,j]);if a[i,j]='@' then begin x1:=i;y1:=j;end;end;
      readln;
    end;
  i:=0;j:=0;
  f[i].x:=x1;
  f[i].y:=y1;
  while i<>ff(j) do
    begin
      if f[i].x>1 then if a[f[i].x-1,f[i].y]='.' then
        begin
          a[f[i].x-1,f[i].y]:=' ';
          inc(ans);
          inc(j);
          f[j].x:=f[i].x-1;f[j].y:=f[i].y;
        end;
      if f[i].x<n then if a[f[i].x+1,f[i].y]='.' then
        begin
          a[f[i].x+1,f[i].y]:=' ';
          inc(ans);
          inc(j);
          f[j].x:=f[i].x+1;f[j].y:=f[i].y;
        end;
      if f[i].y>1 then if a[f[i].x,f[i].y-1]='.' then
        begin
          a[f[i].x,f[i].y-1]:=' ';
          inc(ans);
          inc(j);
          f[j].x:=f[i].x;f[j].y:=f[i].y-1;
        end;
      if f[i].y<m then if a[f[i].x,f[i].y+1]='.' then
        begin
          a[f[i].x,f[i].y+1]:=' ';
          inc(ans);
          inc(j);
          f[j].x:=f[i].x;f[j].y:=f[i].y+1;
        end;
      inc(i);
    end;
  writeln(ans);
end.