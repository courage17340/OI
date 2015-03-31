type rec=record x,y:longint;end;
var
  a:array[1..8] of rec;
  b:array[1..3,1..3] of boolean;
  n,i,j,k:longint;
  t:rec;
function yes:string;
var
  i,j,k:longint;
  p:array[1..6] of rec;
begin
  fillchar(b,sizeof(b),0);
  b[2,2]:=true;
  p[1].x:=a[1].x;p[1].y:=1;
  p[2].x:=a[4].x;p[2].y:=2;
  p[3].x:=a[6].x;p[3].y:=3;
  p[4].x:=a[1].y;p[4].y:=1;
  p[5].x:=a[2].y;p[5].y:=2;
  p[6].x:=a[3].y;p[6].y:=3;
  for i:=1 to 2 do
    if p[i].x=p[i+1].x then exit('ugly');
  for i:=4 to 5 do
    if p[i].x=p[i+1].x then exit('ugly');
  for i:=1 to 8 do
    begin
      for j:=1 to 3 do if a[i].x=p[j].x then break;
      for k:=4 to 6 do if a[i].y=p[k].x then break;
      b[j,k-3]:=true;
    end;
  for i:=1 to 3 do
    for j:=1 to 3 do
      if not b[i,j] then exit('ugly');
  exit('respectable');
end;
begin
  for i:=1 to 8 do readln(a[i].x,a[i].y);
  for i:=1 to 7 do
    for j:=i+1 to 8 do
      if (a[i].x>a[j].x)or(a[i].x=a[j].x)and(a[i].y>a[j].y) then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
        end;
  writeln(yes);
end.