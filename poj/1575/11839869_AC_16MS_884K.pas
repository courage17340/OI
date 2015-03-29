var
  s:string;
function f(ch:char):longint;
begin
  case ch of
    'a','e','i','o','u':exit(1);
  end;
  exit(2);
end;
function yes(s:string):boolean;
var
  i,j:longint;
  p:boolean;
begin
  p:=false;
  for i:=1 to length(s) do if s[i] in ['a','e','i','o','u'] then p:=true;
  if not p then exit(false);
  for i:=1 to length(s)-1 do
    if (s[i]=s[i+1])and(s[i]<>'o')and(s[i]<>'e') then exit(false);
  for i:=1 to length(s)-2 do
    if (f(s[i])=f(s[i+1]))and(f(s[i+1])=f(s[i+2])) then exit(false);
  exit(true);
end;
begin
  while true do
    begin
      readln(s);
      if s='end' then break;
      write('<',s,'> is ');
      if yes(s) then writeln('acceptable.') else writeln('not acceptable.');
    end;
end.