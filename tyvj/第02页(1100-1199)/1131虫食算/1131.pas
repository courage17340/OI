{虫食算}
const max=26;
var
 f:array['A'..'Z'] of longint;{每个字母的值}
 a,b,c,order:array[-max..max] of char;{order 搜索顺序}
 i,j,n:longint;
 s1,s2,s3:string;
 flag:array['A'..'Z'] of boolean;{这个字母是否搜出解}
 hash:array[-max..max] of boolean;{这个数字是否搜过}
 ch:char;
procedure init;
begin
 readln(n);
 readln(s1);readln(s2);readln(s3);
 fillchar(a,sizeof(a),0);
 fillchar(b,sizeof(b),0);
 fillchar(c,sizeof(c),0);
 fillchar(order,sizeof(order),0);
 fillchar(flag,sizeof(flag),false);
 for ch:='A' to 'Z' do f[ch]:=0;
 for i:=1 to n do
  begin
   a[i]:=s1[i];
   b[i]:=s2[i];
   c[i]:=s3[i];
  end;
 j:=0;
 for i:=n downto 1 do
  begin
   if not flag[a[i]] then
    begin
     inc(j);order[j]:=a[i];flag[a[i]]:=true;
    end;
   if not flag[b[i]] then
    begin
     inc(j);order[j]:=b[i];flag[b[i]]:=true;
    end;
   if not flag[c[i]] then
    begin
     inc(j);order[j]:=c[i];flag[c[i]]:=true;
    end;
  end;{从右往左按照字母出现顺序}
 if j<>n then
  for ch:='A' to 'Z' do
   begin
    if not flag[ch] then
     begin
      inc(j);flag[ch]:=true;order[j]:=ch;
     end;
    if j>=n then break;
   end;{有字母未出现过}
 fillchar(flag,sizeof(flag),false);
end;

procedure print;
var i:longint;
begin
 i:=0;
 for ch:='A' to 'Z' do
  begin
   inc(i);
   if i<n then write(f[ch],' ') else writeln(f[ch]);
   if i>=n then begin readln;readln;halt;end;
  end;
end;

function work:boolean;
var
 i,m:longint;
 up:array[-max..max] of longint;{进位}
begin
 fillchar(up,sizeof(up),0);
 up[n]:=1;
 for i:=n downto 1 do
  begin
   if flag[a[i]] and flag[b[i]] and flag[c[i]] then{ABC都知道}
    begin
     m:=f[a[i]]+f[b[i]];
     case up[i] of
      0:begin {0不知道 1不进位 2进位}
        if (m mod n<>f[c[i]])and((m+1) mod n <>f[c[i]]) then exit(false);
        if m div n<>0
         then up[i-1]:=2
         else if (m+1) div n <>0
          then up[i-1]:=2
          else up[i-1]:=1;
       end;
      1:begin
        if m mod n<>f[c[i]] then exit(false);
        if m div n<>0 then up[i-1]:=2 else up[i-1]:=1;
       end;
      2:begin
        inc(m);
        if m mod n<>f[c[i]] then exit(false);
        if m div n<>0 then up[i-1]:=2 else up[i-1]:=1;
       end;
     end;
    end
     else
      if flag[a[i]] and flag[b[i]] then
       begin
        m:=f[a[i]]+f[b[i]];
        case up[i] of
         0:begin
           if (hash[m mod n]=false)and(m div n<>0)
            then up[i-1]:=2
            else if (hash[(m-1) mod n]=false)and((m+1) div n<>0)
              then up[i-1]:=2
              else up[i-1]:=1;
           if not hash[m mod n] and not hash[(m+1) mod n] and (m=n-1) then up[i-1]:=0;
           if hash[m mod n] and hash[(m+1) mod n] then exit(false);
          end;
         1:begin
           if m div n<>0 then up[i-1]:=2 else up[i-1]:=1;
           if hash[m mod n] then exit(false);
          end;
         2:begin
           if m div n<>0 then up[i-1]:=2 else up[i-1]:=1;
           inc(m);
           if hash[m mod n] then exit(false);
          end;
        end;
       end else
        if flag[a[i]] and flag[c[i]] then
         begin
          m:=f[c[i]]-f[a[i]];
          case up[i] of
           0:begin
             if not hash[m mod n] and (f[c[i]]<f[a[i]])
              then up[i-1]:=2
              else
               if hash[(m-1) mod n] and (f[c[i]]-1<f[a[i]])
                then up[i-1]:=2
                else up[i-1]:=1;
             if not hash[m mod n] and not hash[(m-1) mod n] and (f[c[i]]=f[a[i]]) then up[i-1]:=0;
             if m<0 then inc(m,n);
             if hash[ m mod n] and hash[(m-1) mod n] then exit(false);
            end;
           1:begin
             if f[c[i]]<f[a[i]] then up[i-1]:=2 else up[i-1]:=1;
             if m<0 then inc(m,n);
             if hash[m mod n] then exit(false);
            end;
           2:begin
             if f[c[i]]-1<f[a[i]] then up[i-1]:=2 else up[i-1]:=1;
             dec(m);
             if m<0 then inc(m,n);
             if hash[m mod n] then exit(false);
            end;
          end;
         end else
          if flag[b[i]] and flag[c[i]] then
           begin
            m:=f[c[i]]-f[b[i]];
            case up[i] of
             0:begin
               if not hash[m mod n] and (f[c[i]]<f[b[i]])
                then up[i-1]:=2
                else if not hash[(m-1) mod n] and (f[c[i]]-1<f[b[i]])
                  then up[i-1]:=2
                  else up[i-1]:=1;
               if not hash[m mod n] and not hash[(m-1) mod n] and (f[c[i]]=f[b[i]]) then up[i-1]:=0;
               if m<0 then inc(m,n);
               if hash[m mod n] and hash[(m-1) mod n] then exit(false);
              end;
             1:begin
               if f[c[i]]<f[b[i]] then up[i-1]:=2 else up[i-1]:=1;
               if m<0 then inc(m,n);
               if hash[m mod n] then exit(false);
              end;
             2:begin
               if f[c[i]]-1<f[b[i]] then up[i-1]:=2 else up[i-1]:=1;
               dec(m);
               if m<0 then inc(m,n);
               if hash[m mod n] then exit(false);
              end;
            end;
           end;
  end;
 work:=true;
end;

procedure main(depth:longint);
var i:longint;
begin
 if depth>n then print;
 for i:=n-1 downto 0 do
  if hash[i]=false then
   begin
    flag[order[depth]]:=true;{order[depth]这个字母搜过了}
    f[order[depth]]:=i;
    hash[i]:=true;{i这个数字搜过了}
    if not work then
     begin
      flag[order[depth]]:=false;
      hash[i]:=false;
      f[order[depth]]:=0;
      continue;
     end;
    hash[i]:=true;
    main(depth+1);
    f[order[depth]]:=0;
    hash[i]:=false;
    flag[order[depth]]:=false;
   end;
end;

begin
 init;
 main(1);
end.
