var
  n,i,j,k:longint;
  s,t:string;
function f(a,b:string):string;
var
  i,j:longint;
  s,t:string;
begin
  if length(a)>length(b) then
    begin
      s:=a;a:=b;b:=s;
    end;
  s:='';
  for i:=1 to length(a) do if length(a)-i+1>length(s) then
    for j:=length(a)+1-i downto 1 do
      if (j>length(s)) and (pos(copy(a,i,j),b)>0) then
        begin
          s:=copy(a,i,j);
          break;
        end;
  t:=b;
  b:='';
  for i:=1 to length(t) do b:=t[i]+b;
  t:='';
  for i:=1 to length(a) do if length(a)-i+1>length(t) then
    for j:=length(a)+1-i downto 1 do
      if (j>length(t)) and (pos(copy(a,i,j),b)>0) then
        begin
          t:=copy(a,i,j);
          break;
        end;
  if length(s)>length(t) then exit(s) else exit(t);
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(k);
      readln(s);
      t:='';
      for j:=2 to k do
        begin
          readln(t);
          s:=f(s,t);
        end;
      writeln(length(s));
    end;
end.