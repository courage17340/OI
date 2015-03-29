var
  ans,i:longint;
  s:string;
function f(ch:char):longint;
begin
  if ch=' ' then exit(0);
  exit(ord(ch)-64);
end;
begin
  while true do
    begin
      readln(s);
      if s='#' then break;
      ans:=0;
      for i:=1 to length(s) do ans:=ans+f(s[i])*i;
      writeln(ans);
    end;
end.