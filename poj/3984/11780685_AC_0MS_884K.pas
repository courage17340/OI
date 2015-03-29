type rec=record x,y,father:longint;end;
var
  a:array[0..4,0..4] of longint;
  v:array[0..4,0..4] of boolean;
  b:array[1..30] of rec;
  i,j:longint;
procedure print;
var
  a:array[1..25] of longint;
  n,i:longint;
begin
  i:=j;n:=1;
  while i<>1 do
    begin
      i:=b[i].father;
      inc(n);
    end;
  for i:=1 to n do
    begin
      a[n+1-i]:=j;
      j:=b[j].father;
    end;
  for i:=1 to n do
    writeln('(',b[a[i]].x,', ',b[a[i]].y,')');
  halt;
end;
begin
  fillchar(v,sizeof(v),false);
  fillchar(b,sizeof(b),0);
  for i:=0 to 4 do
    for j:=0 to 4 do
      read(a[i,j]);
  i:=1;
  j:=1;
  v[0,0]:=true;
  while i<j+1 do
    begin
      if (b[i].x+1 in [0..4])and(a[b[i].x+1,b[i].y]=0)and(not v[b[i].x+1,b[i].y]) then
        begin
          v[b[i].x+1,b[i].y]:=true;
          inc(j);
          b[j].father:=i;
          b[j].x:=b[i].x+1;
          b[j].y:=b[i].y;
          if (b[j].x=4)and(b[j].y=4) then print;
        end;
      if (b[i].x-1 in [0..4])and(a[b[i].x-1,b[i].y]=0)and(not v[b[i].x-1,b[i].y]) then
        begin
          v[b[i].x-1,b[i].y]:=true;
          inc(j);
          b[j].father:=i;
          b[j].x:=b[i].x-1;
          b[j].y:=b[i].y;
          if (b[j].x=4)and(b[j].y=4) then print;
        end;
      if (b[i].y+1 in [0..4])and(a[b[i].x,b[i].y+1]=0)and(not v[b[i].x,b[i].y+1]) then
        begin
          v[b[i].x,b[i].y+1]:=true;
          inc(j);
          b[j].father:=i;
          b[j].x:=b[i].x;
          b[j].y:=b[i].y+1;
          if (b[j].x=4)and(b[j].y=4) then print;
        end;
      if (b[i].y-1 in [0..4])and(a[b[i].x,b[i].y-1]=0)and(not v[b[i].x,b[i].y-1]) then
        begin
          v[b[i].x,b[i].y-1]:=true;
          inc(j);
          b[j].father:=i;
          b[j].x:=b[i].x;
          b[j].y:=b[i].y-1;
          if (b[j].x=4)and(b[j].y=4) then print;
        end;
      inc(i);
    end;
end.