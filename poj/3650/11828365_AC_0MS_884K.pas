var
  s:string;
  i,j:longint;
begin
  while true do
    begin
      readln(s);
      if s='#' then break;
      for i:=1 to length(s) do
        case s[i] of
          ' ':write('%20');
          '!':write('%21');
          '$':write('%24');
          '%':write('%25');
          '(':write('%28');
          ')':write('%29');
          '*':write('%2a');
          else write(s[i]);
        end;
      writeln;
    end;
end.