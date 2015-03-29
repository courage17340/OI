var
  a:array[1..1300000] of boolean;
  b:array[0..100100] of longint;
  n,i,j,x:longint;
function search(x,L,r:longint):longint;
var
  m:longint;
begin
  if L=r-1 then exit(L);
  m:=(L+r) shr 1;
  if x<b[m] then exit(search(x,L,m));
  exit(search(x,m,r));
end;
begin
  fillchar(a,sizeof(a),true);
  a[1]:=false;
  i:=2;
  while i<trunc(sqrt(1300000)) do
    begin
      while not a[i] do inc(i);
      for j:=2 to 1300000 div i do a[i*j]:=false;
      inc(i);
    end;
  j:=0;
  b[0]:=0;
  for i:=2 to 1300000 do
    if a[i] then
      begin
        inc(j);
        b[j]:=i;
      end;
  while true do
    begin
      readln(x);
      if x=0 then break;
      if a[x] then
        begin
          writeln(0);
          continue;
        end;
      i:=search(x,1,100001);
      writeln(b[i+1]-b[i]);
    end;
end.