var
  a:array[-50..100,-50..100] of boolean;
  n,i,j,k,ans,x1,y1,x2,y2,x3,y3,x,y,r:longint;
  ch:char;
function circle(p,q:longint):boolean;
begin
  circle:=(p-x)*(p-x)+(q-y)*(q-y)<=r*r;
end;
function square(p,q:longint):boolean;
begin
  square:=(p>=x)and(q>=y)and(p<=x+r)and(q<=y+r);
end;
function S(x1,y1,x2,y2,x3,y3:longint):longint;
begin
  S:=abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
end;
function triangle(p,q:longint):boolean;
var s0,s1,s2,s3:longint;
begin
  s0:=S(x1,y1,x2,y2,x3,y3);
  s1:=S(p,q,x2,y2,x3,y3);
  s2:=S(x1,y1,p,q,x3,y3);
  s3:=S(x1,y1,x2,y2,p,q);
  triangle:=s0=s1+s2+s3;
end;
begin
  fillchar(a,sizeof(a),false);
  readln(n);
  for k:=1 to n do
    begin
      read(ch);
      case ch of
        'C':begin
      readln(x,y,r);
      for i:=-50 to 100 do
        for j:=-50 to 100 do
          if not a[i,j] then a[i,j]:=circle(i,j);
            end;
        'S':begin
      readln(x,y,r);
      for i:=-50 to 100 do
        for j:=-50 to 100 do
          if not a[i,j] then a[i,j]:=square(i,j);
            end;
        'T':begin
      readln(x1,y1,x2,y2,x3,y3);
      for i:=-50 to 100 do
        for j:=-50 to 100 do
          if not a[i,j] then a[i,j]:=triangle(i,j);
            end;
      end;
    end;
  ans:=0;
  for i:=-50 to 100 do
    for j:=-50 to 100 do
      if a[i,j] then inc(ans);
  writeln(ans);
  readln;
end.