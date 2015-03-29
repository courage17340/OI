var
  n,a,i:longint;s:string;
begin
  readln(n);
  for i:=1 to n do
   begin
    readln(s);a:=ord(s[length(s)])-48;
    if odd(a) then writeln('odd') else writeln('even');
   end;
end.