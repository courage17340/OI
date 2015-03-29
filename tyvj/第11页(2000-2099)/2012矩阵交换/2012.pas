var
  a:array[1..701,1..701] of longint;
  b,c:array[1..701] of longint;
  n,i,j,k,x,y:longint;
  ch:char;
procedure change(t,x,y:longint);
var j:longint;
begin
  if t=1 then
    begin
      j:=b[x];b[x]:=b[y];b[y]:=j;
    end;
  if t=2 then
    begin
      j:=c[x];c[x]:=c[y];c[y]:=j;
    end;
end;
begin
  readln(n,k);
  for i:=1 to n do
    begin
      for j:=1 to n do read(a[i,j]);
      readln;
    end;
  for i:=1 to n do b[i]:=i;
  for i:=1 to n do c[i]:=i;
  for i:=1 to k do
    begin   
      read(ch);readln(x,y);
      case ch of
        'A':writeln(a[b[x],c[y]]);
        'R':change(1,x,y);
        'C':change(2,x,y);
      end;
    end;
  readln;
end.
