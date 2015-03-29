type rec=record x,step:longint;end;
var
  n,i,j,x,k:longint;
  v:array[0..70000] of boolean;
  b:array[1..70000] of rec;
  ch:char;
function f(x,p:longint):longint;
var
  i,j:longint;
begin
  f:=x xor (1 shl (16-p));
  if p>4 then f:=f xor (1 shl (20-p));
  if p<13 then f:=f xor (1 shl (12-p));
  if p mod 4<>1 then f:=f xor (1 shl (17-p));
  if p mod 4<>0 then f:=f xor (1 shl (15-p));
end;
procedure print(x:longint);
begin
  writeln(x);
  readln;readln;
  halt;
end;
begin
  fillchar(v,sizeof(v),false);
  x:=0;
  for i:=1 to 16 do
    begin
      read(ch);
      while not (ch in ['w','b']) do read(ch);
      x:=x*2;
      if ch='b' then inc(x);
    end;
  i:=1;
  j:=1;
  b[1].x:=x;
  b[1].step:=0;
  v[x]:=true;
  if (x=0)or(x=65535) then print(0);
  while i<j+1 do
    begin
      for k:=1 to 16 do if not v[f(b[i].x,k)] then
        begin
          inc(j);
          b[j].step:=b[i].step+1;
          b[j].x:=f(b[i].x,k);
          v[f(b[i].x,k)]:=true;
          if (b[j].x=0)or(b[j].x=65535) then print(b[j].step);
        end;
      inc(i);
    end;
  writeln('Impossible');
end.